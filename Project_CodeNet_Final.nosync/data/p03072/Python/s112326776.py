n = int(input())
h = list(map(int,input().split()))

s = 1

for i in range(1,n):
    if(h[i] >= max(h[:i])):s += 1
print(s)