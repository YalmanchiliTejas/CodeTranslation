
import sys
#sys.stdin=open("data.txt")
input=sys.stdin.readline

MOD=10**9+7

def powmod(b,e):
    global MOD
    if e==0: return 1
    if e&1: return (powmod((b*b)%MOD,e//2)*b)%MOD
    return powmod((b*b)%MOD,e//2)

n=int(input())
h=[1]+list(map(int,input().split()))

"""
# naive solution, O(sum h_i)
archive=[]

# do rows
a1=[1]
for i in range(1,n+1):
    if h[i]<=h[i-1]:
        c=0
        while len(a1)>h[i]:
            c+=a1.pop(-1)
        a1[0]=((a1[0]+c)*2)%MOD
    else:
        a1[0]=(a1[0]*2)%MOD
        mul=powmod(2,h[i]-h[i-1])
        for j in range(1,len(a1)):
            a1[j]=(a1[j]*mul)%MOD
        extras=[a1[0]]
        for _ in range(h[i]-h[i-1]-1):
            extras.append(extras[-1]*2)
        a1+=extras[::-1]
    archive.append(a1)

print(sum(a1)%MOD)
"""

# smarter solution? i think it's O(N^2)
root=1      # number of times that this column just alternates
pos=[]      # [x,y] means it starts at x, and its size is y blocks
sz=1
for i in range(1,n+1):
    if h[i]<=h[i-1]:
        c=0
        while pos and sz-pos[-1][1]>=h[i]:
            a,b=pos.pop(-1)
            c+=(a*(powmod(2,b)-1))%MOD
            sz-=b
        if sz>h[i]:
            a,b=pos.pop(-1)
            pos.append([(a*powmod(2,sz-h[i]))%MOD,b-(sz-h[i])])
            c+=(a*(powmod(2,sz-h[i])-1))%MOD
            sz=h[i]
        root=((root+c)*2)%MOD
    else:
        root=(root*2)%MOD
        mul=powmod(2,h[i]-h[i-1])
        for j in range(len(pos)):
            pos[j][0]=(pos[j][0]*mul)%MOD
        pos.append([root,h[i]-h[i-1]])
        sz=h[i]

# get answer
for a,b in pos:
    root+=(a*(powmod(2,b)-1))%MOD
print(root%MOD)