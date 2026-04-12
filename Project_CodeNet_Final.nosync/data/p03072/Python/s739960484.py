N = int(input())
H = list(map(int, input().split()))

x = H[0]
ma = 0
ct = 0

for Hi in H:
    
    if ma < Hi:
        ma = Hi
    if Hi >= ma:
        ct += 1

print(ct)