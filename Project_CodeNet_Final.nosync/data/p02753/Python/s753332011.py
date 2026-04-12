A = False
B = False
s=input()
for char in s:
    if char == "A":
        A = True
    if char == "B":
        B = True
if(A and B):
    print("Yes")
else:
    print("No")