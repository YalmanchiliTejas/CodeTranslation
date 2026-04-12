s = input()
t = int(input())
e1 = eval(s)

e2 = int(s[0])
i = 1
while i < len(s):
    x = int(s[i+1])
    if s[i] == '+':
        e2 += x
    else:
        e2 *= x
    i += 2

if e1 == t and e2 == t:
    print("U")
elif e1 == t:
    print("M")
elif e2 == t:
    print("L")
else:
    print("I")