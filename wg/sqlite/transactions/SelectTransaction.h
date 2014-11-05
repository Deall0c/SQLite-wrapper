#ifndef WG_SELECTTRANSACTION_H
#define WG_SELECTTRANSACTION_H

#include "../../wg_utils.h"
#include "../structs.h"
#include <string>
#include <sstream>
#include <vector>

namespace wg
{
	namespace sqlite
	{
		namespace transactions
		{
			WG_USE_STRING; // include std::string
			WG_USE(vector);
			WG_USE(stringstream);

			class SelectTransaction
			{
			public:
				SelectTransaction();
				~SelectTransaction();
				SelectTransaction* from(string table); // define from which table we query
				SelectTransaction* from(string table, string alias); // defines from which table we query (allows alias)
				SelectTransaction* select(string field); // select which fields we take
				SelectTransaction* where(string field, string eq, string val); // select what field has to match what value
				SelectTransaction* where(string field, string val); // select what field has to match what value
				SelectTransaction* orWhere(string field, string eq, string val); // select what field has to match what value
				SelectTransaction* orWhere(string field, string val); // select what field has to match what value
				SelectTransaction* andWhere(string field, string eq, string val); // select what field has to match what value
				SelectTransaction* andWhere(string field, string val); // select what field has to match what value
				const string build();
			private:
                string _current;
				vector<wg_table*> *_tables = NULL;
				vector<string> *_selects = NULL;
				vector<wg_where*> *_wheres = NULL;
			};
		}
	}
}

#endif
