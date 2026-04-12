n = int(input())
a = list(map(int, input().split()))
s = 0
for i in range(n): 
    s = s + a[i] 

e = s * s 

ss = 0
for i in range(n): 
    ss += a[i] * a[i] 
p =  (e - ss) // 2
print(p % (10**9 + 7))