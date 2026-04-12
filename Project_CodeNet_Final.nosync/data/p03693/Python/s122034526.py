l    = input().split()
r, g, b = map(int, l)

val = r * 100 + g * 10 + b
mod_4 = divmod(val, 4)
mod_4 = mod_4[1]

if mod_4 == 0 :
    print('YES')
else :
    print('NO')