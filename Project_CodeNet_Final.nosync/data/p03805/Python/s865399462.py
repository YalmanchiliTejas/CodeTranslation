import sys
import itertools
 
 
def check(i,array):
    now=0
    while True:
        flag=0
        if(now==len(i)-1):
            return 1
        for x in array:
            if(i[now]==x[0] and i[now+1]==x[1] or \
                i[now]==x[1] and i[now+1]==x[0]):
 
                flag=1
                now+=1
                break
 
        if(flag==0):
            return 0
 
 
def main():
    N, M = map(int,input().split())
 
    array=[]
    sum=0
 
    for _ in range(0, M):
        array.append(list(map(int,input().split())))
 
 
    for i in itertools.permutations(range(1,N+1),N):
        if(i[0]==1):
            sum += check(i,array)
    print(sum)
 
main()