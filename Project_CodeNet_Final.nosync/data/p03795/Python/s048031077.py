N = int(input())

x = N * 800
y = 0

for i in range(1,N+1):
    if i % 15 == 0:
        y = y + 200

ans = x-y        
print(ans)