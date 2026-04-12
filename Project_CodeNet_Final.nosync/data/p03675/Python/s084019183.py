a = int(input())
ar = list(map(int,input().split(" ")))
br = []
for i in range(a-1,-1,-2):
    br.append(ar[i])
if a % 2 == 0:
    n = 0
else:
    n = 1
for i in range(n,a-1,2):
    br.append(ar[i])
for i in range(a-1):
    print(br[i],end=" ")
print(br[a-1])