n = input()

hs = input()
hs = hs.split()

count = 0
max_hs = 0

for hss in hs:
    hss = int(hss)
    max_hs = max(hss, max_hs)
    if hss >= max_hs:
        count += 1

print(count)
