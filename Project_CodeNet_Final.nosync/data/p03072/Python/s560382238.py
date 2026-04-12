n = int(input())
h = list(map(int,input().split()))
a = 0
for i in range(1,len(h)):
    if h[i] >= max(h[:i]):
        a += 1
print(a+1)