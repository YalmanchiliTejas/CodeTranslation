# coding: utf-8
def q0():
    while True:
        data=[]
        n=int(input())
        if n==0:
            return
        for i in range(n):
            data.append(int(input()))
        print((sum(data)-max(data)-min(data))//(n-2))

def q1():
    while True:
        n,r=map(int,input().split())
        if n==0:
            return
        deck=[n-i for i in range(n)]
        for i in range(r):
            p,c=map(int,input().split())
            deck=deck[p-1:p-1+c]+deck[0:p-1]+deck[p-1+c:]
        print(deck[0])


question=[q0,q1]

question[0]()
