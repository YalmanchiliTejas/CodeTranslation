n = int(input())
s = input()
k = int(input())
s_list = list(s) 
for i in range(0 , n) :
    if s_list[i] != s_list[k-1] :
        s_list[i] = "*"
a = "".join(s_list)
print(a)