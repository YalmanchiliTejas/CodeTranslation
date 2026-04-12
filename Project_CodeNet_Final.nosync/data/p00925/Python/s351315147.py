# -*- coding: utf-8 -*-

S = input()
bob = int(input())

M = eval(S)

L = int(S[0])

for o, v in zip(S[1::2], S[2::2]):
    if o == "*":
        L *= int(v)
    else:
        L += int(v)

if M == L == bob:
    print("U")
elif M == bob:
    print("M")
elif L == bob:
    print("L")
else:
    print("I")
