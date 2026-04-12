
def s_to_dict(s):
    word_dict = {}
    for i in s:
        if i in word_dict:
            word_dict[i] += 1
        else:
            word_dict[i] = 1
    return word_dict
# print(s_to_dict("asdfgesa"))
# {'a': 2, 's': 2, 'd': 1, 'f': 1, 'g': 1, 'e': 1}

#dict1 = {'a': 2, 's': 2, 'd': 1, 'f': 1, 'g': 1, 'e': 1}
#dict2 = {'a': 2, 's': 2, 'd': 1, 'f': 1, 'm': 1, 'e': 1}

def intersection_dict(dict1,dict2):
    new_dict = {}
    key_set = set(dict1.keys()) & set(dict2.keys())
    for key in key_set:
        new_dict[key] = min(dict1[key],dict2[key])
    #print(new_dict)
    return new_dict
#intersection_dict(dict1,dict2)

n = int(input())

first_dict = s_to_dict(input())
current_dict = first_dict
for i in range(n-1):
    current_dict = intersection_dict(current_dict,s_to_dict(input()))
#rint(current_dict)

sorted_keys = sorted(current_dict.keys())
#print(sorted_keys)
ans = ""
for key in sorted_keys:
    ans += (current_dict[key])*key
print(ans)