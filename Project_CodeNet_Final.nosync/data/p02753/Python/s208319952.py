S = input()

if all(i == "A" for i in S) or all(i == "B" for i in S):
    print("No")
else:
    print("Yes")