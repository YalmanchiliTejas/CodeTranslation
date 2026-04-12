ans = []

while True:
    n, l, r = map(int, input().split())
    if n + l + r == 0:
        break

    a = []
    for i in range(n):
        a.append(int(input()))
   
    cnt = 0
    for x in range(l, r + 1):
        
        for j in range(n):
            if x % a[j] == 0:
                if (j + 1) % 2 == 1:
                    cnt += 1
                break
            elif j == (n - 1):
                if n % 2 == 0:
                    cnt += 1
                 
    ans.append(cnt)

for i in ans:
    print(i)

