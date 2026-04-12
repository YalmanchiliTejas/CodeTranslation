a=int(input())
List=list(map(int,input().split()))
c = 0

for i in range(a):
    if max(List[:i+1]) == List[i]:
        c +=1
print(c)