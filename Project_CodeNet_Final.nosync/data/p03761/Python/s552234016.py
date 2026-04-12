
a = int(input())
b = []
c = []
ans = ""

for i in range(a):
    b.append(input())
    c.append(len(b[i]))

alpha = [chr(i) for i in range(97,97+26)]

for ii in range(26):
    d = []
    for i in range(a):
        d.append(b[i].count(alpha[ii]))
    ans = ans + (alpha[ii] * min(d))
           
print(ans)