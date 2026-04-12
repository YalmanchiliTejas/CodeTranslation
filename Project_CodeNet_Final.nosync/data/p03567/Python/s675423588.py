def is_contained_ac(s):
    for i in range(len(s)-1):
        if s[i:i+2] == "AC":
            return True
    return False

s = input()
if is_contained_ac(s): 
    print("Yes")
else:
    print("No")