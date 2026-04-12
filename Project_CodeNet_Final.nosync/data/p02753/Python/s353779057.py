s = list(input())
flaga = 0
flagb = 0
for i in range(len(s)):
    if s[i] == "A":
        flaga = 1
    if s[i] == "B":
        flagb = 1

if flaga == 1 and flagb == 1:
    print("Yes")
else:
    print("No")