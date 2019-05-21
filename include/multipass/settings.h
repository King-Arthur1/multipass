/*
 * Copyright (C) 2019 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_SETTINGS_H
#define MULTIPASS_SETTINGS_H

#include "singleton.h"

#include <QString>

#include <map>

namespace multipass
{
class Settings : public Singleton<Settings>
{
public:
    Settings(const Singleton<Settings>::PrivatePass&);

    // throws std::out_of_range on unknown key
    virtual QString get(const QString& key) const;
    virtual void set(const QString& key, const QString& val);

protected:
    // throws std::out_of_range on unknown key
    const QString& get_default(const QString& key) const;

private:
    std::map<QString, QString> defaults;
};
} // namespace multipass

#endif // MULTIPASS_SETTINGS_H
