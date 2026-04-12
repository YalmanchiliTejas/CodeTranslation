n = input()
_h = input()
_h = list(map(int, _h.split(' ')))

ans = 0

for i, h in enumerate(_h):
    if i == 0:
        max_h = h
        ans = ans + 1
        continue
    
    if h < max_h:
        continue
    else:
        max_h = h
    
    if h >= _h[i-1]:
        ans = ans + 1

print(ans)