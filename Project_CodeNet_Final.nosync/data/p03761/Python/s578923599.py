n = int(input())

out = ""
s1 = input()
s = [list(input()) for _ in range(n-1)]

for i in s1:
    if all([i in x for x in s]):
        out += i
        for j in s:
            j.remove(i)


print("".join(sorted(out)))
