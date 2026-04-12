s = int(input())
List=list(map(int,input().split()))
a = 0
b=List[0]
for i in range(s):
    if b <= List[i]:
        a +=1
        b = List[i]

print(a)