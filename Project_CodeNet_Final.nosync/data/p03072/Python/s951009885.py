a = int(input())
b = map(int,input().split())
b = list(b)
k = 1
for i in range(a-1):
    maxim = max(b[:i+1])
    if maxim <= b[i+1]:
        k += 1
print(k)