input1 = input()
input2 = list(input())
input3 = input()
for i in range(0,len(input2)):
    if input2[i] != input2[int(input3)-1]:
        input2[i] = "*"
print("".join(input2))