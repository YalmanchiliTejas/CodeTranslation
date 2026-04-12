def input_int():
    return map(int, input().split())

def one_int():
    return int(input())

def one_str():
    return input()

def many_int():
    return list(map(int, input().split()))

S=one_str()

if len(set(S))<=1:
    print("No")
else:
    print("Yes")