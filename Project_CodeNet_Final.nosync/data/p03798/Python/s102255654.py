from logging import getLogger, StreamHandler, DEBUG
logger = getLogger(__name__)
handler = StreamHandler()
handler.setLevel(DEBUG)
logger.setLevel(DEBUG)
logger.addHandler(handler)

import sys

def saySame(s, sw, index):
    return (sw[index] == 'S' and s[index] == 'o') or (sw[index] == 'W' and s[index] == 'x')
    
def match(s, sw, index, N):
    if saySame(s,sw,index):
        return sw[(index - 1 + N) % N] == sw[(index + 1 + N) % N]
    else:
        return sw[(index - 1 + N) % N] != sw[(index + 1 + N) % N]

N = int(input())
s = input()

for j in range(4):
    sw = ""
    if j%2==0:
        sw+= 'S'
    else:
        sw+= 'W'

    if (int(j/2))%2==0:
        sw+= 'S'
    else:
        sw+= 'W'
#    logger.debug(sw)


    for i in range(N-2):
        if saySame(s,sw,i+1):
            sw+=sw[i]
        else:
            if sw[i] == 'S':
                sw+='W'
            else:
                sw+='S'

#        logger.debug(sw)

    if match(s,sw,0,N) and match(s,sw,N-1,N):
        print(sw)
        sys.exit()

print(-1)
