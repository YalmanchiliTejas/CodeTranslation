N = int(input())
yama = [0]
visble = 0
takasa = list(map(int,input().split()))
for n in range(N):
    if max(yama) <= takasa[n]:
        visble += 1
    yama.append(takasa[n])
print(visble)