in_data = [input() for i in range(3)] 
 
n = int(in_data[0])
s = in_data[1]
k = int(in_data[2])





target_c = s[k - 1]
new_s = ''
for c in s:
    if c == target_c:
        new_s += c
    else:
        new_s += '*'
 
print(new_s)