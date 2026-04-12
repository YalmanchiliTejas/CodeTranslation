s = input()
n = len(s) # sの長さn

a_only = "A" * n # Aがn文字続く文字列
b_only = "B" * n # Bがn文字続く文字列 

if s == a_only or s == b_only:
    print("No")
else:
    print("Yes")