S = input()
companies = {company for company in S}
if len(companies) > 1:
    print('Yes')
else:
    print('No')