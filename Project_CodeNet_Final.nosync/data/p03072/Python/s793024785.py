n = int(input())
m = list(map(int, input().split()))
b = m[0]
b2 = m[0]
t = 0
for i in range(len(m)):
    if(m[i]>=b2):
        t += 1
        b2 = m[i]
print(t)