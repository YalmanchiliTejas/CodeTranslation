a = int(input())
L = list(map(int, input().split()))
n = 1
box = L[0] 
for i in range(a-1):
    if box <= L[i+1]:
        n = n+1
        box = L[i+1]
print(n)