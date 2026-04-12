N = int(input())
H = map(int, input().split())

mx = 0 
res = 0 
for n in H:
    if n >= mx: 
        res += 1
        mx = n 
print(res)