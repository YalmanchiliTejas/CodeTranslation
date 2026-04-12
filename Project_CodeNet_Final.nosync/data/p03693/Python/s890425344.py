def abc():
    rgb = ''.join(input().split())
    print('NO' if int(rgb) % 4 else 'YES')


abc()
