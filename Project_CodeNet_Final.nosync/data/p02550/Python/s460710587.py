n,x, m = map(int, input().split())
mod = [None for _ in range(m)]
count = x
loop = []
rem = [x]
for i in range(1, n):
    value = (x * x) % m
    rem.append(value)
    x = (x * x) % m
    if mod[value] != None:
        # print(mod)
        s_index = mod[value]
        loop = rem[s_index : -1]
        num = (n - s_index) // len(loop)
        amari = (n - s_index) % len(loop)
        if amari == 0:
            print(sum(rem[:s_index]) + sum(loop) * num) 
        else:
            print(sum(rem[:s_index]) + sum(loop) * num + sum(loop[:amari])) 
        exit()
    else:
        mod[value] = i
        count += value
print(count)
