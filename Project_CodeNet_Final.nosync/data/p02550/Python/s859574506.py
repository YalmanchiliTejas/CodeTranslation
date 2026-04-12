n, x, m = map(int, input().split())

def f(x, m):
    return x % m

a = x
a_set = {a}
a_array = [a]
a_index = 0
while(True):
    a = f(a ** 2, m)
    if a in a_set:
        a_index = a_array.index(a)
        break
    a_set.add(a)
    a_array.append(a)


a_iter_array = a_array[a_index:]
div, mod = divmod(n - a_index, len(a_iter_array))
ans = sum(a_array[:a_index]) + sum(a_iter_array) * div + sum(a_iter_array[:mod])
print(ans)