#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int start, pos, text_len=strlen(text), key_len=strlen(key); 
    for(start=0; start<(text_len-key_len); start++){
        for(pos=0; pos<key_len; pos++){
            if(text[start+pos]==key[pos]){
                if(pos==key_len-1){
                   return  text+start;
                }else{

                }
            }else{
                break;
            }
        }
    }
return NULL;
}

char* BMSearch(char text[], char key[])
{
    int index, key_index, text_len=strlen(text), key_len=strlen(key),table[256];
    for(index=0; index<256; index++){
        table[index]=key_len;
    }
    for(index=0; index<key_len; index++){
        int pos = key_len-index-1;
        char c = key[index];
        table[(int)c]=pos;
    }
    index = key_len - 1;
    while(index<text_len){
        for(key_index=key_len-1; key_index>=0; key_index--, index--){
            if(text[index]==key[key_index]){
                if(key_index==0){
                    return text+index;
                }
            }else{
                break;
            }
        }

        int new_index=index+table[(int)text[index]];
        if(new_index<=index){
            index++;
        } else{
            index=new_index;
        }
    }
    return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}