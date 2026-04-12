n, x, m = map(int, input().split())
mod_value = [-1 for i in range(2*m)] #余りの値を頭から格納
mod_check = [False for i in range(m)] #余りが現れたか否か
value = x
i = 0
head = 0
while i < n:
    if not mod_check[value]:
        mod_value[i] = value
        mod_check[value] = True
        i += 1
        value = (value**2)%m
    else:
        head = mod_value.index(value)
        break
if i == n:
    print(sum(mod_value[:n]))
else:
    block_size = i - head
    block_num = (n-head)//block_size
    print(sum(mod_value[:head]) + sum(mod_value[head:i])*block_num + sum(mod_value[head:head+(n-head)%block_size]))