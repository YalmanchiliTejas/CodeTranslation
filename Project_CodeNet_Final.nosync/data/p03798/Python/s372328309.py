# coding: utf-8
# Here your code !
import sys
N = int(input())
ipt = list(input())
stR = ["S" for i in range(N)]

def sheep(stg):
     return stg
def wolf(stg):
    if stg == "S":
        return "W"
    else:
        return "S"
def modN (i):
    return i%N
def check ( num1,num2 ):
    stR[0]=num1
    stR[1]=num2
    for i in range(N+2):
        if stR[modN(i+1)] == "S" and ipt[modN(i+1)]=="o"  :
            stR[modN(i+2)]=sheep(stR[modN(i)])
        elif stR[modN(i+1)] == "W" and ipt[modN(i+1)]=="x":
            stR[modN(i+2)]=sheep(stR[modN(i)])
        else:
            stR[modN(i+2)]=wolf(stR[modN(i)])
    
    if stR[0]==num1 and stR[1]==num2:
        print("".join(stR))
        return True
    else:
        return False

if check("S","W"):
    sys.exit()
else:
    
    if check("W","W"):
        sys.exit()
    else:
        
        if check("W","S"):
            sys.exit()
        else:
            
            if check("S","S"):
                sys.exit()
            else:
                print(-1)

