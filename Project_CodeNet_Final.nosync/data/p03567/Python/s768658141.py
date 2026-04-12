# -*- coding: utf-8 -*-
def inpl(): return tuple(map(int, input().split()))

S = input()
for i in range(len(S)-1):
    if S[i] + S[i+1] == "AC":
        print("Yes")
        break
else:
    print("No")