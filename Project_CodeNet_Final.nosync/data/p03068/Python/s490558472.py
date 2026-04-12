N = int(input())
s = input()
p = int(input())
sl = list(s)
c = sl[p-1]
sp = map(lambda x:"*" if x != c else x, sl)
print("".join(sp))