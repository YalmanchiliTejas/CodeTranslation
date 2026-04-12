#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(void){
    string bit = "";
    int code;

    while(1){
        code = fgetc(stdin);
        if(code == EOF) break;
        switch(code){
            case 'A': bit += "00000"; break;
            case 'B': bit += "00001"; break;
            case 'C': bit += "00010"; break;
            case 'D': bit += "00011"; break;
            case 'E': bit += "00100"; break;
            case 'F': bit += "00101"; break;
            case 'G': bit += "00110"; break;
            case 'H': bit += "00111"; break;
            case 'I': bit += "01000"; break;
            case 'J': bit += "01001"; break;
            case 'K': bit += "01010"; break;
            case 'L': bit += "01011"; break;
            case 'M': bit += "01100"; break;
            case 'N': bit += "01101"; break;
            case 'O': bit += "01110"; break;
            case 'P': bit += "01111"; break;
            case 'Q': bit += "10000"; break;
            case 'R': bit += "10001"; break;
            case 'S': bit += "10010"; break;
            case 'T': bit += "10011"; break;
            case 'U': bit += "10100"; break;
            case 'V': bit += "10101"; break;
            case 'W': bit += "10110"; break;
            case 'X': bit += "10111"; break;
            case 'Y': bit += "11000"; break;
            case 'Z': bit += "11001"; break;
            case ' ': bit += "11010"; break;
            case '.': bit += "11011"; break;
            case ',': bit += "11100"; break;
            case '-': bit += "11101"; break;
            case '\'':bit += "11110"; break;
            case '?': bit += "11111"; break;
        }
        if(code != '\n') continue;

        struct {
            const char *p;
            char ch;
        } b[] = {
            { "000000"      ,'\'' },
            { "000001"      ,'?'  },
            { "000010"      ,'W'  },
            { "000011"      ,','  },
            { "0001"        ,'D'  },
            { "00100"       ,'L'  },
            { "00101"       ,'O'  },
            { "00110"       ,'S'  },
            { "00111"       ,'T'  },
            { "010000"      ,'H'  },
            { "010001"      ,'.'  },
            { "01001"       ,'F'  },
            { "0101"        ,'C'  },
            { "0110"        ,'K'  },
            { "0111"        ,'I'  },
            { "1000"        ,'R'  },
            { "10010000"    ,'Z'  },
            { "10010001"    ,'-'  },
            { "10010010"    ,'X'  },
            { "10010011"    ,'Y'  },
            { "100101"      ,'A'  },
            { "10011000"    ,'J'  },
            { "10011001"    ,'M'  },
            { "10011010"    ,'B'  },
            { "10011011"    ,'G'  },
            { "10011100"    ,'U'  },
            { "10011101"    ,'V'  },
            { "10011110"    ,'N'  },
            { "10011111"    ,'Q'  },
            { "101"         ,' '  },
            { "110"         ,'E'  },
            { "111"         ,'P'  },
        };

        const char *p = bit.c_str();

        while(p[0] != 0){
            int flag = 0;
            for(int i = 0; i < sizeof(b)/sizeof(b[0]); i++){
                int len = strlen(b[i].p);
                if(strlen(p) < len) continue;
                if(strncmp(p, b[i].p, len) == 0){
                    printf("%c", b[i].ch);
                    p += len;
                    flag = 1;
                    break;
                }
            }
            if(!flag) break;
        }
        printf("\n");
        bit = "";
    }

    return 0;
}