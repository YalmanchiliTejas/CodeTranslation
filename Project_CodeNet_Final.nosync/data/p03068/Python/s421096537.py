n = int(input())
s = input()
k = int(input())

replace = s[k-1]
list_2 = list(s)

for i in range(len(s)):
    if list_2[i] != replace:
        list_2[i] = "*"
    
s = "".join(list_2)
print(s)