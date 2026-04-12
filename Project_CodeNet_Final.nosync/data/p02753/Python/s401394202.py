#n=int(input())
#a,b=map(int,input().split())
#l=list(map(int,input().split()))
#l=[list(map(int,input().split())) for i in range(n)]

s=list(input())

if s.count("A")==3 or s.count("B")==3 :
    print("No")
else:
    print("Yes")
