n = int(input())
*H, = map(int, input().split())
a = 0
for i in range(n):
    a += (max(H[:i+1]) == H[i])
print(a)