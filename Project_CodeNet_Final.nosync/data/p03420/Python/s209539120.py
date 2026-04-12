num = map(int,raw_input().split())
n = num[0]
k = num[1]

tot = 0

for i in range(n - k):
    s = n / (k + i + 1)
    t = n % (k + i + 1) - k + 1
    if t < 0:
        t = 0
    tot += s * (i + 1) + t

if k == 0:
    tot -= n 
    
print tot