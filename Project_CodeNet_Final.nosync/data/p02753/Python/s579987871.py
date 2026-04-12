s = input()

def a(s):
    for i, s_i in enumerate(s):
        if s_i != s[i-1]:
            return 'Yes'

    return 'No'

print(a(s))