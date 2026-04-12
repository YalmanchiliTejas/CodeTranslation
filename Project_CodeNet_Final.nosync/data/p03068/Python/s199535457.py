n=3
string_list=[input() for i in range(n)]
c=''
for strng in string_list[1]:
    if strng==string_list[1][int(string_list[2])-1]:
        c+=strng
    else:
        c+='*'
print(c)