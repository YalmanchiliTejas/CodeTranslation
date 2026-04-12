import sys

def MultiBurger(n,x):
    """
    レベルnバーガーの下からx枚に含まれるパティの量を計算する関数
    nBurger = 0 + n-1Burger + 1 + n-1Burger + 0
    0Burger = 1
    b=0
    p=1
    """
    sum=( 1<<n+2 )-3
    #sum: 総数
    middle=( 1<<n+1 )-1
    #middle: 真ん中のパティの番号
    num=(middle-1)//2
    #num: 1レベル小さいバーガーのパティの数

    if n==0 and x==1:
        return 1
    elif x==1:
        return 0

    elif x<middle-1:
        return MultiBurger(n-1,x-1)
    elif x==middle-1:
        return num
    elif x==middle:
        return num+1
    elif middle<x<sum-1:
        return num+1+MultiBurger(n-1,x-middle)
    else:
        return num*2+1
    
INPUT=input().split()
N=int(INPUT[0])
X=int(INPUT[1])
Paty=MultiBurger(N,X)

print(Paty)