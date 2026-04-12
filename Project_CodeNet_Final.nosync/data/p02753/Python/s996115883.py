def f():
    S = raw_input()
    return 'Yes' if len(set(S)) == 2 else 'No'

print(f())