k = int(input())
line = input()

m = []
am = 1
for n in range(k):
    m.append(int(line.split()[n]))
    if(n==0):
        tallest = m[n]
    if(n>0):
        tallest = max(m[n], tallest)
        coef = m[n] - tallest
        if(coef>=0):
            am+=1
print(am)