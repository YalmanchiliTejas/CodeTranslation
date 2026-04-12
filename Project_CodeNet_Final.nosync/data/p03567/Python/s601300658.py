#  --*-coding:utf-8-*--

def f(s):
    return 'Yes' if (s.find('AC') != -1) else 'No'

def test():
    assert f('BACD') == 'Yes'
    assert f('ABCD') == 'No'
    assert f('CABD') == 'No'
    assert f('ACACA') == 'Yes'
    assert f('XX') == 'No'


def main():
    print(f(input()))


if __name__ == '__main__':
    main()
