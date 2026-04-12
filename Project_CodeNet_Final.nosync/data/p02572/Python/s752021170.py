nn = int(input())
aa = list(map(int, input().split()))
bb = [0]*(nn-1)
mysum = sum(aa) % (10**9 + 7)
mydiff = 0

for i in range(1,nn):
    mydiff += aa[i - 1]
    tete = mysum - mydiff
    if tete >= 0:
        bb[i-1] = tete
    else:
        bb[i-1] = tete + 10**9+7

finalsum = 0
for i in range(nn-1):
        finalsum += aa[i]*bb[i]
        finalsum = finalsum % (10**9 + 7)

print(finalsum)