S = input()

sl = [s for s in S]

def main():
    cnta = sl.count('A')
    cntb = sl.count('B')
    if cnta in (0,3) or cntb in (0,3):
        return 'No'
    else:
        return 'Yes'

print(main())
