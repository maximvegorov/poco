//
// SortedTableModel.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/SortedTableModel.h#4 $
//
// Library: WebWidgets
// Package: Views
// Module:  SortedTableModel
//
// Definition of the SortedTableModel class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef WebWidgets_SortedTableModel_INCLUDED
#define WebWidgets_SortedTableModel_INCLUDED


#include "Poco/WebWidgets/WebWidgets.h"
#include "Poco/WebWidgets/TableModel.h"
#include "Poco/AutoPtr.h"
#include "Poco/Any.h"
#include <vector>


namespace Poco {
namespace WebWidgets {

	class Table;


class WebWidgets_API SortedTableModel: public TableModel
	/// SortedTableModel defines the interface for data retrieval for a Table
{
public:
	typedef Poco::AutoPtr<SortedTableModel> Ptr;

	SortedTableModel(const Table* pTable, std::size_t col, bool sortAscending);
		/// Creates the SortedTableModel.Sorts pModel via col and if sortWithLess is 
		/// true by less otherwise by more

	const Poco::Any& getValue(std::size_t row, std::size_t col) const;
		///Returns the value at pos(row, col) or an empty Any if no data is stored there

	std::size_t getRowCount() const;
		/// Returns the total number of rows

	void setValue(const Poco::Any& val, std::size_t row, std::size_t col);
		/// Sets the value at pos(row, col)

	void deleteRow(std::size_t row);
		/// Removes the row from the SortedTableModel
		
	void clear();
		/// Deletes all rows from the SortedTableModel	

	void sort(std::size_t col, bool sortAscending);
		/// Only sorts if col and direction is different

	void forceResort(std::size_t col, bool sortAscending);
		/// Forced resort

	std::size_t getSortedColumn() const;

	std::size_t mapping(std::size_t) const;

protected:
	virtual ~SortedTableModel();
		/// Destroys the SortedTableModel.
private:
	TableModel&     _unsorted;
	const Table*    _pTable;
	std::size_t     _sortCol;
	bool            _sortAscending;
	std::vector<std::size_t> _mapping;
};



inline std::size_t SortedTableModel::mapping(std::size_t row) const
{
	if (_sortAscending)
		return _mapping[row];
	return _mapping[_mapping.size() - row -1 ];
}


inline std::size_t SortedTableModel::getSortedColumn() const
{
	return _sortCol;
}

} } // namespace Poco::WebWidgets


#endif // WebWidgets_SortedTableModel_INCLUDED
