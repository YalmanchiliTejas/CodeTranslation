
s = input()

a_count = 0
b_count = 0

for i in s:
    if i == 'A':
        a_count+=1
    if i == 'B':
        b_count+=1

if a_count == 3 or b_count ==3:
    print("No")
else:
    print("Yes")
